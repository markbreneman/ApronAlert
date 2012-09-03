print 'running... Apron Alert'

# import libraries
import twitter
import serial
import time

# connect to arduino via serial port:chand serial port accordingly
arduino = serial.Serial('/dev/tty.usbmodem411', 9600, timeout=1)


# establish OAuth id with twitter replace with your tokens
api = twitter.Api(consumer_key='4GjtPnNjRNSe1AbaFCwu0g',
                  consumer_secret='xSYerezdOiSGTycIokeNY0S3HpvQp2zrp7PMQxEwc',
                  access_token_key='739156903-nLGgs2KLWEwLTytNe7xfLSlTx9fRRLHS0oA4QAVp',
                  access_token_secret='sjdljsRJY3qSVsoVcnTqyAmsE4I3XdX69aG5qdb6kw')

# listen to arduino
def listenToArduino():
    msg=arduino.readline()
    if msg > '':
        print 'arduino msg: '+msg.strip()
        compareMsg(msg.strip())

# avoid duplicate posts
def compareMsg(newMsg):
    # compare the first word from new and old
    status = api.GetUserTimeline('ApronAlert')
    prevMsg = [s.text for s in status]
    pM = ""+prevMsg[0]+""
    pM = pM.split()
    nM = newMsg.split()
    print "prevMsg: "+pM[0]
    print "newMsg: "+nM[0]
    if pM[0] != nM[0]:
        print "bam"
        postMsg(newMsg)

# post new message to twitter
def postMsg(newMsg):
    localtime = time.asctime(time.localtime(time.time()))
    tweet = api.PostUpdate(newMsg+", "+localtime)
    print "tweeted: "+tweet.text

while 1:
    listenToArduino()