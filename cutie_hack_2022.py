import smtplib

SMTP_SERVER = 'smtp.gmail.com' 
SMTP_PORT = 587 
GMAIL_USERNAME = 'tsha813@gmail.com'
GMAIL_PASSWORD = '' #blank for security reasons =)  


class Emailer:
    def sendmail(self, recipient, subject, content):

        headers = ["From: " + GMAIL_USERNAME, "Subject: " + subject, "To: " + recipient,
                   "MIME-Version: 1.0", "Content-Type: text/html"]
        headers = "\r\n".join(headers)
        
        session = smtplib.SMTP(SMTP_SERVER, SMTP_PORT)
        session.ehlo()
        session.starttls()
        session.ehlo()

        session.login(GMAIL_USERNAME, GMAIL_PASSWORD)

        session.sendmail(GMAIL_USERNAME, recipient, headers + "\r\n\r\n" + content)
        session.quit

sender = Emailer()
sendTo = 'legocat813@gmail.com'
emailSubject = "OI OI OI PANIC"
emailContent = "Something is going very wrong and you have to do something about it"
import serial

ser = serial.Serial('/dev/ttyACM0',9600)
s = [0]
while True:
    #s[0] = str(int (ser.readline(),16))
    s[0] = ser.readline()
    print (s[0])
        #gas, cm, smoke, flame
    
    if(s[0] == b'smoke\r\n'):
         sender.sendmail(sendTo, "Smoke has been detected in area", "The device has detected high levels of smoke in the area, please investigate.")
    
    if(s[0] == b'cm\r\n'):
        sender.sendmail(sendTo, "High levels of Carbon Monoxide detected in area", "The device has detected high levels of carbon monoxide in the area, please investigate.")
        
    if(s[0] == b'flame\r\n'):
        sender.sendmail(sendTo, "Fire detected in area", "The device has detected fire in the area, please investigate.")

#Sends an email to the "sendTo" address with the specified "emailSubject" as the subject and "emailContent" as the email content.
#sender.sendmail(sendTo, emailSubject, emailContent)