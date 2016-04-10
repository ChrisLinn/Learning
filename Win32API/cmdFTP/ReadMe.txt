使用说明：
使用之前先使用记事本软件打开"upload"和"download"文件填写FTP服务器信息

“upload”、”download”文件必须和编译出来的程序放在相同目录下，可以用记事本打开，其中保存了配置信息
其中
	“put 1.txt htdocs/1.txt “表示把本地exe相同目录下的1.txt文件上传到服务器并保存为服务器的1.txt，可以改成“put D:\2.txt htdocs/1.txt “之类的，这样就将D盘下的2.txt上传到服务器。
	“get htdocs/1.txt 1.txt“表示把服务器的1.txt下载下来并保存为本地exe相同目录下的1.txt文件，可以改成“get htdocs/1.txt D:\2.txt“之类的，这样就会保存为D盘下的2.txt


	
原理：
借用命令行下直接使用的命令"ftp -s:filename"

上传，直接添加使用下面这句命令即可：
	system("ftp -s:upload");
	执行后会把exe同目录下的 1.txt 上传到服务器。
下载，直接添加使用下面这句命令即可：
	system("ftp -s:download");
	执行后会把服务器上的数据下载并保存为exe同目录下的 1.txt


	ShellExecute的效果不好，没有进度显示，就算加了对话框点下按钮直接就弹框了