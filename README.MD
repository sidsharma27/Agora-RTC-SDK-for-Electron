## Agora.io RTC SDK for Electron

#### Electron is a framework for creating native desktop applications with web technologies like JavaScript, HTML, and CSS. Using Agora’s Electron SDK you can add real time voice, video, and interactive broadcasting to your desktop applications with ease. To get started add the following files


### Build :
1. Install NODEJS and GYP.
2. Run build.bat script.
If MSVC version or Electron version is not the same as the script, change the corresponding parameters in the script. Electron 1.8.3 or later version need vs2015 or above.


### Code structure:
1. agora_node_ext : NODEJS C++ ADDON which wraps functionalities of Agora Native SDK.
2. common : Utilities that used by agora_node_ext and video source
3. video source : agora_node_ext implement multiple video sources functionality by using multiple processes. Video source provides the ancillary facilities.
4. js : Contains JS level API.
5. sdk : Agora Native SDK, used to generate NODEJS ADDON.
6. demon : one very simple demon.




