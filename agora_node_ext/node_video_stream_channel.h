/*
* Copyright (c) 2017 Agora.io
* All rights reserved.
* Proprietary and Confidential -- Agora.io
*/

/*
*  Created by Wang Yongli, 2017
*/

#ifndef NODE_VIDEO_STREAM_CHANNEL_H
#define NODE_VIDEO_STREAM_CHANNEL_H

#include <memory>
#include <mutex>
#include <array>
#include <atomic>
#include "agora_rtc_engine.h"
#pragma once

namespace agora {
    namespace rtc {
        struct NodeRenderContext;

        /**
         * NodeVideoStreamChannel is used to transfer video data from SDK to JS layer.
         */
        class NodeVideoStreamChannel
        {
        public:
            NodeVideoStreamChannel(NodeRenderContext* context);
            ~NodeVideoStreamChannel();

            int deliverFrame(const agora::media::IVideoFrame& videoFrame, int rotation, bool mirrored);

        private:
            struct image_header_type {
                uint8_t format;
                uint8_t mirrored;
                uint16_t width;
                uint16_t height;
                uint16_t left;
                uint16_t top;
                uint16_t right;
                uint16_t bottom;
                uint16_t rotation;
                uint32_t timestamp;
            };
            
            int deliverFrame_I420(const agora::media::IVideoFrame& videoFrame, int rotation, bool mirrored, buffer_list& buffers);
            void setupFrameHeader(image_header_type *header, int stride, int width, int height);
            void copyFrame(const agora::media::IVideoFrame& videoFrame, unsigned char *buffer, int dst_stride, int src_stride, int width, int height, buffer_list& buffers);
        private:
            typedef std::vector<unsigned char> stream_buffer_type;
            std::unique_ptr<NodeRenderContext> m_context;
            stream_buffer_type m_buffer;
            buffer_list buffers;
            std::atomic_bool m_render;
        };
    }
}

#endif
