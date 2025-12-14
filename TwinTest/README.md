1、读取配置文件：
通过蓝图函数库UCockpitConfigLibrary读取配置文件，配置文件用于配置领导驾驶舱的菜单按钮url. ,配置文件位置saved/config/windows/cockpit.ini, 打包后需手工复制。
未实现：UDeveloperSettings实现编辑器配置面板

2、Offline Speech Recognition（离线语音识别）
一个语音转录插件，将语音转换为文本，支持离线使用。

好的，下面是实现 UE5 C++ 插件“Offline Speech Recognition”离线语音识别的核心步骤，满足您的要求：
•	从麦克风采集音频
•	使用 Vosk 本地语音识别库进行识别
•	在 UMG 的 Text 文本框中显示识别结果
---
1. 插件依赖与准备
1.	下载并集成 Vosk API 到您的 UE5 项目插件目录（通常是 Plugins/OfflineSpeechRecognition/ThirdParty/Vosk）。
2.	添加 Vosk 的头文件和库文件到插件的 Build.cs：
https://alphacephei.com/vosk
	1. 

UE5.5 C++版本，实现离线语音识别插件，通过ASpeechToTextActor,采集麦克风音频，使用Vosk本地语音识别库进行识别，识别结果广播到蓝图。蓝图可调用StartCapture()开启语音捕捉, StopCapture()停止语音捕捉。要求，写出所有完整的代码。