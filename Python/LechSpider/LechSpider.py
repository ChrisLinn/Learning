#!/usr/bin/env python
#-*- coding: utf-8 -*-
#通过urllib(2)模块下载网络内容
import urllib,urllib2,gevent
#引入正则表达式模块，时间模块
import re,time
from gevent import monkey
monkey.patch_all()
   

def mkdir(path):
    # 引入模块
    import os
    # 去除首位空格
    path=path.strip()
    # 去除尾部 \ 符号
    path=path.rstrip("\\")
    # 判断路径是否存在
    # 存在     True
    # 不存在   False
    isExists=os.path.exists(path)
    # 判断结果
    if not isExists:
        # 如果不存在则创建目录
        # 创建目录操作函数
        os.makedirs(path)
        return True
    else:
        # 如果目录存在则不创建，并提示目录已存在
        return False

def geturllist(url):
    urlf_list = []
    print "Page Analyzing"
    print url       
    s = urllib2.urlopen(url)
    text = s.read()
    #正则匹配，匹配其中的图片   
    html = re.search(r'contentBody.+?</div>', text, re.S)
    urls = re.finditer(r'src="http://beauty.easylife.tw/files/attach/images/(.+?)jpg"',html.group(),re.I)
    fns = re.finditer(r'alt="(.+?)jpg"',html.group(),re.I)   
    for i in urls:
        url=str("http://sahost.easylife.tw/beauty/attach/images/")+i.group(1).strip()+str("jpg")
        print "Found!"
        print url
        urlf_list.append(url)
    for j in fns:
        filename=j.group(1).strip()+str("jpg")
        print 'Recognized!'
        print filename
        urlf_list.append(filename)
    html = re.search(r'title="分類"><a(.+?)</div>',text,re.S)    
    cns = re.finditer(r'">(?!<)(.+?)</a>',html.group(),re.I)
    for h in cns:
    	catename=h.group(1).strip()
    print catename
    urlf_list.append(catename)
    html = re.search(r'<title>.+?</title>', text, re.S)    
    pns = re.finditer(r'低調收藏 - (.+?)</title>',html.group(),re.I)
    for h in pns:
    	pathname=h.group(1).strip()
    print pathname
    urlf_list.append(pathname)
    print 'Hah!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'
    mkdir("./1/"+catename+"/"+pathname)
    return urlf_list
    
   
def download(down_url,file_name,cate_name,path_name):
    name=re.sub('.+?/','',down_url)
    print "Downlod        "+file_name
    urllib.urlretrieve(down_url, "./1/"+cate_name+"/"+path_name+"/"+file_name)

def getpageurl():
    page_list = []
    #进行列表页循环
    for page in range(1,700):
        #url="http://beauty.easylife.tw/index.php?mid=board&page="+str(page)
        url="http://jandan.net/ooxx/page-"+str(page)+"#comments"
	#把生成的url加入到page_list中
        page_list.append(url)
    #print page_list
    return page_list
if __name__ == '__main__':
    jobs = []
    #pageurl = getpageurl()
    #进行图片下载
    pageurl = "http://beauty.easylife.tw/index.php?mid=board&page=10&document_srl=230134"
    #for i in pageurl:
    #    for (downurl) in geturllist(i):
    urlf_list = geturllist(pageurl)
    l = len(urlf_list)
    for k in range(l/2-1):
            jobs.append(gevent.spawn(download, urlf_list[k],urlf_list[k+l/2-1],urlf_list[l-2],urlf_list[l-1]))
    gevent.joinall(jobs)