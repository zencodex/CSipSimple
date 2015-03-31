# CSipSimple

CSipSimple 是个款通用的支持SIP协议的互联网电话软件，可以在支持andriod的平板，手机上使用。

# 带编译环境虚拟机

配置好编译环境的virtualbox虚拟机：
链接：http://pan.baidu.com/s/1ntsqwPz 密码：4fhs

虚拟机中代码路径：
/home/build/code.Proj

备份官方svn仓储代码路径：
/home/build/backup

虚拟磁盘格式为vmdk，也可以挂载到vmware或者parallels虚拟机中使用。

---

本源码仓储由官方SVN转成git，并由ZenCodex 维护，如果有问题，请邮件联系 v@yinqisen.cn

中国CSipSimple爱好者QQ交流群：13945450
ZenCodex's Blog：http://yinqisen.cn

---

This project will allow native sip for android device.

It relies on the pjsip sip stack project.

Supported features :

    SIP for calls and instant messages
    Android integration with rewriting and filtering rules
    Codecs : pcmu/a (aka g711u/a); speex; g722; gsm; iSAC; SILK; G729; AMR (depending on device) and as extra plugin : OPUS; g726; g722.1; codec2
    Echo cancellation (with various backends : webRTC, speex, simple)
    Auto speaker/earpiece option
    API provided for other apps plugins.
    Conference, transfer.
    Secure call with TLS transport for SIP and SRTP or ZRTP for media. 

