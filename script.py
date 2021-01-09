import os
import datetime

today = str(datetime.date.today()).split('-')

folder_name = today[0][2:] + today[1] + today[2]

if not os.path.isdir("./{}".format(folder_name)):
    os.mkdir("./{}".format(folder_name))