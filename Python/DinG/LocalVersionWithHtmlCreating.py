#!/usr/bin/env python
# -*- coding: utf-8 -*-
#import webapp2
import json
import urllib2
import time
import os
'''
class MainHandler(webapp2.RequestHandler):
	def get(self):
		self.response.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>我看豆瓣</title><link rel="shortcut icon" href="http://img3.douban.com/pics/douban-icons/favicon_32x32.png" type="image/x-icon" /></head><body>')
		#self.response.write('<script type="text/javascript" src="//ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js"></script><script type="text/javascript"> function getData(){ alert("js弹");}</script><input align="center" id="Button1" type="button" value="js弹" onclick="getData()" />')
		self.response.write('</br>')
		api = urllib2.urlopen('http://api.douban.com/shuo/v2/statuses/user_timeline/NanderFour?count=20')
		sta=json.loads(api.read())
		time.sleep(2)
		for i in {'ByronYi','14315980','57662586','56780447','4809702','58779892','10566855','55949617','imdreamrunner','walkanlearn','yuyu066','79668988','germinga','Scarltee'}:
			api = urllib2.urlopen('http://api.douban.com/shuo/v2/statuses/user_timeline/'+i+'?count=20')
			sta2=json.loads(api.read())
			time.sleep(2)
			sta=sta+sta2
		sta = sorted(sta,reverse=True,key = lambda x:x['id'])
		api.close()
		for i in range(len(sta)):
			if ('reshared_status' in sta[i].keys()):
				self.response.write('</br><div align="center">'+sta[i]['user']['screen_name']+' '+sta[i]['title']+'</br>'+sta[i]['reshared_status']['user']['screen_name']+u' 说:'+'</br>'+sta[i]['reshared_status']['text']+'</br>')
			else:
				self.response.write('</br><div align="center">'+sta[i]['user']['screen_name']+' '+sta[i]['title']+'</br>')
			self.response.write('<a href="http://www.douban.com/people/'+sta[i]['user']['uid']+'/status/'+str(sta[i]['id'])+'/">'+'www.douban.com/people/'+sta[i]['user']['uid']+'/status/'+str(sta[i]['id'])+'/'+'</a>')
			self.response.write('</br></br></div>')
		#self.response.write('<ul id="list"></ul>')
		self.response.write('</body></html>')

app = webapp2.WSGIApplication([
	('/', MainHandler)
], debug=True)
'''



if __name__=="__main__":
	f=open('DinG.html','wt')
	f.write(u'<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><META http-equiv="Content-Type" content="text/html; charset=UTF-8"><title>我看豆瓣</title><link rel="shortcut icon" href="http://img3.douban.com/pics/douban-icons/favicon_32x32.png" type="image/x-icon" /></head><body>'.encode("UTF-8"))
	f.write('</br>'.encode("UTF-8"))
	api = urllib2.urlopen('http://api.douban.com/shuo/v2/statuses/user_timeline/NanderFour?count=200')
	print 'Me\n'
	sta=json.loads(api.read())
	#time.sleep(2)
	li=['ByronYi','14315980','56780447','4809702','58779892','10566855','55949617','imdreamrunner','walkanlearn','yuyu066','79668988','germinga','Scarltee']#,'57662586'
	for k in range(len(li)):
	#for i in {'ByronYi','14315980','57662586','56780447','4809702','58779892','10566855','55949617','imdreamrunner','walkanlearn','yuyu066','79668988','germinga','Scarltee'}:
		api = urllib2.urlopen('http://api.douban.com/shuo/v2/statuses/user_timeline/'+li[k]+'?count=200')
		sta2=json.loads(api.read())
		#time.sleep(2)
		print li[k]
		print str((k+1.0)/len(li)*100)+'%\n'
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
'''

from creepy import Crawler
from BeautifulSoup import BeautifulSoup
import urllib2
import json
 
class MyCrawler(Crawler):
    def process_document(self, doc):
        if doc.status == 200:
            print '[%d] %s' % (doc.status, doc.url)
            try:
                soup = BeautifulSoup(doc.text.decode('gb18030').encode('utf-8'))
            except Exception as e:
                print e
                soup = BeautifulSoup(doc.text)
            print soup.find(id="product-intro").div.h1.text
            url_id=urllib2.unquote(doc.url).decode('utf8').split('/')[-1].split('.')[0]
            f = urllib2.urlopen('http://p.3.cn/prices/get?skuid=J_'+url_id,timeout=5)
            price=json.loads(f.read())
            f.close()
            print price[0]['p']
        else:
            pass
 
crawler = MyCrawler()
crawler.set_follow_mode(Crawler.F_SAME_HOST)
crawler.set_concurrency_level(16)
crawler.add_url_filter('\.(jpg|jpeg|gif|png|js|css|swf)$')
crawler.crawl('http://item.jd.com/982040.html')
'''
