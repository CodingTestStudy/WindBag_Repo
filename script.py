# 코딩 테스트 레포 일일 폴더 생성 스크립트
# Windows 작업 스케줄러에 등록하거나 시작프로그램에 등록하여 사용

import os
import datetime

today = str(datetime.date.today()).split('-')

folder_name = today[0][2:] + today[1] + today[2]

if not os.path.isdir("./{}".format(folder_name)):
    os.mkdir("./{}".format(folder_name))

    os.mkdir("./{}/FAIL".format(folder_name))
    os.mkdir("./{}/PASS".format(folder_name))

exit()