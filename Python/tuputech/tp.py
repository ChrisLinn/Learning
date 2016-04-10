#task_name = "porn"
#sID = '566266b9f4b1bdae7e5b9df5'
task_name = "object"
sID = '56a625274ade142c0925f115'

sample_config_file_cont={
"private_key":"""-----BEGIN RSA PRIVATE KEY-----
MIICXQIBAAKBgQC0h8ZKL3SGcHEuaGGRxN4tUIt9JPVgNS6pGBSAHa6N4E7Xve3u
pcXNGVxlNPLOvh/jObRU+b2HZx9O5gaC5sJYPsO5zYGsLGmo0xZkdSkI+U9Bz6Xi
UKG30PMg5ucQOhwOYrlepNEZ05z88CO5yo602gZGaRP4+eOJiEU3e39bewIDAQAB
AoGAEFLupSqhWL62HUInAG1Swbo0wr4iye5FJ9kbkXIdpIqR1oRADYJD3oXaivQ8
uGEMtRk0qzJh5up2NEYsdI21KOqYiKj3iSqOHQSPjRyE/g1bKHXi/lQMJ7+zStIO
YeVxigU5JQ+YZ+KRn3B6yxhX92O4355N/26bTSG7rm8BKSECQQDnSTvEj/NTzD5p
j9+VquNO8NACyR9kl3YG7MK2rG9WSGUlgzl+3RbeHDbqmdLt3QAmhubPI5qNGZUq
fQnQHWvzAkEAx9IiCqnrNnmqO10l6uSXcBVyA6mwu7jgxPgA0b43UWevg2dLN9xc
Vvt1qozxswEIFu5srt0zHOyyvq+4ZYDcWQJAQ4ILsPb3ZhkyimtVLoFfsbX2cSm1
QQ44hBLtTpaMNNoSs91WleIAf7oqiVV2zLj6B0TO790Lim3SLUGr8JP14wJBAJvX
plccyObWos7jyhPVrspq31499SmjeiIErlbm/KvPqxJX+FEb2yS3v8CBZmxOjKmd
0EPdHuUbMhkIYU9A3hkCQQDPduYME2+lGVy+OkkXv8SUT3VzoHAzT5B/gOxCA/4d
+h4+T9d2fHY5GJURZyVEiQY2sJiNu070ZQ1fuvMeE/zk
-----END RSA PRIVATE KEY-----""",
"public_key":"""-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC0h8ZKL3SGcHEuaGGRxN4tUIt9
JPVgNS6pGBSAHa6N4E7Xve3upcXNGVxlNPLOvh/jObRU+b2HZx9O5gaC5sJYPsO5
zYGsLGmo0xZkdSkI+U9Bz6XiUKG30PMg5ucQOhwOYrlepNEZ05z88CO5yo602gZG
aRP4+eOJiEU3e39bewIDAQAB
-----END PUBLIC KEY-----""",
task_name:{
"secretId":sID,
"modelId":'5645e38b986df6d858b35c96',
"url":'http://api.open.tuputech.com/v3/recognition/'+sID}
}

def APITest(pic):
	#images =["/home/vincentchou/TestAPI/images/PICS2.zip"]
	images =[pic]
	import hashlib
	import datetime
	from Crypto.Random import random
	from Crypto.PublicKey import RSA
	from Crypto.Hash.SHA256 import SHA256Hash
	from Crypto.Hash import SHA256
	from Crypto.Signature import PKCS1_v1_5
	import base64
	timestamp_str = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
	nonce_str = str(random.randint(1 << 4, 1 << 32))
	
	task_conf = sample_config_file_cont[task_name]
	
	params = [task_conf['secretId'], timestamp_str, nonce_str]
	params_str = ''.join(["%s," % item for item in params])
	sign_params_str = params_str[:-1] #get rid of the last ','
	
	private_key_str = sample_config_file_cont["private_key"]
	rsa_private_key = RSA.importKey(private_key_str)
	hashed_params = SHA256Hash(sign_params_str)
	signer = PKCS1_v1_5.new(rsa_private_key)
	bin_sign = signer.sign(hashed_params)
	signature_base64 = base64.b64encode(bin_sign)
	
	# it is not needed when you post URL instead of file path.
	files = [('image', (addr[-6:],open(addr, 'rb'), 'image/png')) for addr in images]
	req_body = {
		#'image': urls, ** this field is required if you post as URLs **
		'timestamp': timestamp_str,
		'nonce': nonce_str,
		'signature': signature_base64
	}
	import grequests as requests
	request = requests.post(task_conf['url'], data=req_body, files=files) #files is not required if you post as URLs
	response = request.send()
	print("\n>>>>>>this is raw response content\n")
	print(response.content) # this is raw response content, before its been verified, it can not be trusted.
	print("\nraw content end ======\n")
	
	# verify
	import json
	content = json.loads(response.content)
	recvSignature = content['signature']
	
	json_str = content['json']
	rsakey = RSA.importKey(sample_config_file_cont['public_key'])
	verifier = PKCS1_v1_5.new(rsakey)
	digest = SHA256.new(json_str)
	
	if verifier.verify(digest, base64.b64decode(recvSignature)):
		print "verified!"
	else:
		print "fail"



import os
Const_Image_Format = [".jpg",".jpeg",".bmp",".png",".gif"]
class FileFilt:
    fileList = [""]
    counter = 0
    def __init__(self):
        pass
    def FindFile(self,dirr,filtrate = 1):
        global Const_Image_Format
        for s in os.listdir(dirr):
            newDir = os.path.join(dirr,s)
            if os.path.isfile(newDir):
                if filtrate:
                        if newDir and(os.path.splitext(newDir)[1] in Const_Image_Format):
                            self.fileList.append(newDir)
                            self.counter+=1
                else:
                    self.fileList.append(newDir)
                    self.counter+=1
 
if __name__ == "__main__":
        b = FileFilt()
        b.FindFile(dirr = os.path.split(os.path.realpath(__file__))[0])
        #print(b.counter)
        for pic in b.fileList:
			APITest(pic)