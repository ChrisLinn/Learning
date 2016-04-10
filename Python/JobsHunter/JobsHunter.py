#!/usr/bin/env python
# -*- coding: utf-8 -*-
#import webapp2
import json
import urllib2
import time
import os
import re
from  datetime  import  *  
import  time 
'''
Map
	·先抓取内容
	·存入文件
	·比对是否已有
	提醒
	抓取
		现在使用的是硬编码
		改成数组
	显示职位名字
		先txt大略名字
		再网页
		txt去掉杂字
	检索
		直接txt检索
		采用数据库
Note
	仍有重复
	未进行比对
ToDoList	
	1速度
	2抓董事长问题的解决
	3改成数据库存储而非txt
	4现在职位名只能显示 总监 总经理 总裁 厂长 董事长
	而不能记录为 市场总监这样
	5如果搜索超出一页怎么解决
	6现在都是直接规定职位 最好提供自定义搜索什么职位的功能 放到一个数组里然后逐一抓取
	7提醒功能  现在只是有个黑框告诉说有更新而已
'''

if __name__=="__main__":
	print '\n开始\n\n'
	while 1:
		#time.sleep(2)
		#cnu_list = []
		#newcnu_list = []
		cnu_list = set() 
		newcnu_list = set() 
		
		ZHIWEI = ['总监','总经理','总裁','厂长']
		ZHIWEIBIANMA = ['%E6%80%BB%E7%9B%91','%E6%80%BB%E7%BB%8F%E7%90%86','%E6%80%BB%E8%A3%81','%E5%8E%82%E9%95%BF']
		DIQU = ['广东除深圳','广西','海南','安徽','湖南','江西','云南','河北','新疆','甘肃','山西']#去山东  ， 江西 云南 河北 新疆 甘肃   山西		
		DIQUBIANMA = ['030000','140000','100000','150000','190000','130000','250000','160000','310000','270000','210000']
		for x in range(len(ZHIWEIBIANMA)):
			print ZHIWEI[x]
			print '========'
			for y in range(len(DIQUBIANMA)):
				cn_list = []
				u_list = []
				print DIQU[y]
				print '	读取中'
				s = urllib2.urlopen('http://search.51job.com/jobsearch/search_result.php?fromJs=1&jobarea='+DIQUBIANMA[y]+'&funtype=0000&industrytype=00&keyword='+ZHIWEIBIANMA[x]+'%20-%E5%8A%A9%E7%90%86%20-%E7%A7%98%E4%B9%A6%20-%E5%8F%B8%E6%9C%BA&keywordtype=1&curr_page=1&lang=c&stype=2&postchannel=0000&workyear=99&cotype=99&degreefrom=99&jobterm=01&companysize=99&lonlat=0%2C0&radius=-1&ord_field=0&list_type=0')
				html = s.read()
				s.close()
				data = re.search(r'resultListDiv(.+?)</div>',html,re.S)
				cns = re.finditer(r'coname" target="_blank" >(.+?)</a>',data.group(),re.I)
				for i in cns:
					cn=i.group(1).strip()
					cn_list.append(cn)
				us = re.finditer(r'td2"><a href="(.+?)"',data.group(),re.I)
				for i in us:
					u=i.group(1).strip()
					u_list.append(u)
				l = len(u_list)
				for k in range(l):
					if not ('(' in cn_list[k]):
						#cnu_list.append(u_list[k]+'		'+cn_list[k])
						cnu_list.add(u_list[k]+'		'+cn_list[k]) 
				print '	分析完毕'
			print '\n'
			
		f=open('HR.txt','r')
		print '打开文件'
		txt=f.read()
		for i in cnu_list:
		#	if ((not re.search(i,txt,re.S)) and (i!="厂长	http://search.51job.com/job/64259277,c.html		中恒能(北京)生物能源技术有限公司")):# and (i!="")
			if (not re.search(i,txt,re.S)):
				#newcnu_list.append(i)
				cnu_list.add(u_list[k]+'		'+cn_list[k]) 
		f.close()
		if newcnu_list:
			print '存在新增项'
		 	f=open('HR.txt','a')
			print '添加新增项'
			for k in newcnu_list:
				f.write(k+'\n')
			f.write(str(datetime.now())+'更新\n-------------------------------\n')
			f.close()
			print str(datetime.now())+'更新\n-------------------------------\n\n'
			os.system('HR.txt')
		else:	
			print str(datetime.now())+'没有更新\n\n\n\n'


#只要 总监 总经理 总裁 厂长 董事长 	排除 助理 秘书 司机