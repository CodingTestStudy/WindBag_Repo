N, M = map(int, input().split())

str_short = input()
str_long = input()

isChange = False

if N > M:
    str_short, str_long = str_long, str_short
    isChange = True

str_short = "*" + str_short + "*"
str_long = "*" + str_long + "*"

lst = []

loc = 0
for letter in str_short:
    try:
        if isChange:
            if letter == 'w':
                w = str_long[loc:].find('w')
                v = str_long[loc:].find('v')
                
                tmp = []
                for val in (v, w):
                    if val > -1:
                        tmp.append(val)

                if tmp:
                    lst.append(loc + min(tmp))
                    loc += min(tmp) + 1
                else:
                    lst.append(-1)
            elif letter == 'l':
                l = str_long[loc:].find('l')
                i = str_long[loc:].find('i')

                tmp = []
                for val in (i, l):
                    if val > -1:
                        tmp.append(val)

                if tmp:
                    lst.append(loc + min(tmp))
                    loc += min(tmp) + 1
                else:
                    lst.append(-1)
            elif letter == 'j':
                j = str_long[loc:].find('j')
                i = str_long[loc:].find('i')

                tmp = []
                for val in (j, i):
                    if val > -1:
                        tmp.append(val)

                if tmp:
                    lst.append(loc + min(tmp))
                    loc += min(tmp) + 1
                else:
                    lst.append(-1)
            else:
                lst.append(loc + str_long[loc:].index(letter))
                loc += str_long[loc:].index(letter) + 1 
        else:
            if letter == 'i':
                i = str_long[loc:].find('i')
                j = str_long[loc:].find('j')
                l = str_long[loc:].find('l')
                
                tmp = []
                for val in (i, j, l):
                    if val > -1:
                        tmp.append(val)

                if tmp:
                    lst.append(loc + min(tmp))
                    loc += min(tmp) + 1
                else:
                    lst.append(-1)
            elif letter == 'v':
                v = str_long[loc:].find('v')
                w = str_long[loc:].find('w')

                tmp = []
                for val in (v, w):
                    if val > -1:
                        tmp.append(val)

                if tmp:
                    lst.append(loc + min(tmp))
                    loc += min(tmp) + 1
                else:
                    lst.append(-1)
            else:
                lst.append(loc + str_long[loc:].index(letter))
                loc += str_long[loc:].index(letter) + 1
    except:
        lst.append(-1)

real = []
for i in lst:
    if i != -1:
        real.append(i)

score = 0

for i in range(len(real) - 1):
    score += max(real[i+1] - (real[i] + 1), lst[lst.index(real[i]):lst.index(real[i+1])].count(-1))
    
print(score)