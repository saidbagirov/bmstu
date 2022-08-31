import requests
from bs4 import BeautifulSoup

URL = 'file:///C:/html/html.html'
import iuliia
def make_lat_data(name, namelat):
        with open(name, 'r') as cyr:
                for line in cyr:
                        flag = 0;
                        for i in line:
                                if i.isdigit():
                                        flag = 1;
                                        break;
                        if flag:
                                continue;
                        with open(namelat, 'a') as lat:
                                lat.write(iuliia.translate(line, iuliia.WIKIPEDIA))
def parse():
    soup = BeautifulSoup(open("html.html", encoding='utf8'), "html.parser")
    items = soup.find_all("span", class_ ="fio_com")
    students = []
    i = 0
    for item in items:
        students.append({
            "name": item.get_text()
        })
    for i in range(9):
        items = soup.find_all("td", class_ ="headcol_body", tabindex = i)
        j = 0
        for item in items:
            students[j][i] = item.find("span",class_ = "progress_percent p_all").get_text()
            j += 1
    f = open('data.txt','w')
    i = 0
    for std in students:
        f.write(str(i+1)+ "\n")
        f.write(str(std['name'])+ "\n")
        for j in range(1,9,1):
            f.write(str(std.get(j))+ "\n")
        i += 1
    f.close()
         
    
parse()
make_lat_data("data.txt","lat_data.txt")
