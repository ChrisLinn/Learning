#!/usr/bin/env python
# -*- coding: utf-8 -*-
import json
import urllib2
import time
import os
import androidhelper

droid = androidhelper.Android()
if __name__=="__main__":
	f=open('DinG.html','wt')
	f.write(u'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><META http-equiv="Content-Type" content="text/html; charset=UTF-8"><title>我看豆瓣</title><link rel="shortcut icon" href="http://img3.douban.com/pics/douban-icons/favicon_32x32.png" type="image/x-icon" /></head><body>'.encode("UTF-8"))
	f.write('</br>'.encode("UTF-8"))
	api = urllib2.urlopen('http://api.douban.com/shuo/v2/statuses/user_timeline/NanderFour?count=200')
	#print 'Me\n'
	s= 'Me'
	droid.makeToast(s)
	sta=json.loads(api.read())
	#time.sleep(2)
	li=['ByronYi','14315980','56780447','4809702','58779892','10566855','55949617','imdreamrunner','walkanlearn','yuyu066','79668988','germinga','Scarltee']#,'57662586'
	for k in range(len(li)):
	#for i in {'ByronYi','14315980','57662586','56780447','4809702','58779892','10566855','55949617','imdreamrunner','walkanlearn','yuyu066','79668988','germinga','Scarltee'}:
		api = urllib2.urlopen('http://api.douban.com/shuo/v2/statuses/user_timeline/'+li[k]+'?count=200')
		sta2=json.loads(api.read())
		#time.sleep(2)
		s=  li[k]+'\n'+str((k+1.0)/len(li)*100)+'%'
		droid.makeToast(s)
		sta=sta+sta2
	sta = sorted(sta,reverse=True,key = lambda x:x['id'])
	api.close()
	for i in range(len(sta)):
		if ('reshared_status' in sta[i].keys()):
			f.write('</br><div align="center">'.encode("UTF-8")+sta[i]['user']['screen_name'].encode("UTF-8")+' '.encode("UTF-8")+sta[i]['title'].encode("UTF-8")+'</br>'.encode("UTF-8")+sta[i]['reshared_status']['user']['screen_name'].encode("UTF-8")+u'说:'.encode("UTF-8")+'</br>'.encode("UTF-8")+sta[i]['reshared_status']['text'].encode("UTF-8")+'</br>'.encode("UTF-8"))
		else:
			f.write('</br><div align="center">'.encode("UTF-8")+sta[i]['user']['screen_name'].encode("UTF-8")+' '.encode("UTF-8")+sta[i]['title'].encode("UTF-8")+(('</br>'.encode("UTF-8")) if(sta[i]['text']) else '')+sta[i]['text'].encode("UTF-8")+'</br>'.encode("UTF-8"))
		f.write('<a href="http://www.douban.com/people/'.encode("UTF-8")+sta[i]['user']['uid'].encode("UTF-8")+'/status/'.encode("UTF-8")+str(sta[i]['id']).encode("UTF-8")+'/">'.encode("UTF-8")+'www.douban.com/people/'.encode("UTF-8")+sta[i]['user']['uid'].encode("UTF-8")+'/status/'.encode("UTF-8")+str(sta[i]['id']).encode("UTF-8")+'/</a>'.encode("UTF-8"))
		f.write('</br></br></div>'.encode("UTF-8"))
	#self.response.write('<ul id="list"></ul>')
	f.write('</body></html>')
	f.close()
	#os.system('start DinG.html')

