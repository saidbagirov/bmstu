import sys
from mine import *
mc = Minecraft()

def make_dict(name, namelat):
    f = open(name,'r')
    students = []
    i = 0
    for line in f:
        i += 1
    f.close()
    f = open(name,'r')
    f_lat =open(namelat, 'r')
    for j in range(1,int(i/10),1):
        name_lat = f_lat.readline().rstrip()
        n = f.readline().rstrip()
        name = f.readline().rstrip()
        history = f.readline().rstrip()
        pe = f.readline().rstrip()
        programing = f.readline().rstrip()
        foreign_languge = f.readline().rstrip()
        software_engineering = f.readline().rstrip()
        linear_algebra = f.readline().rstrip()
        physics = f.readline().rstrip()
        integrals = f.readline().rstrip()
        students.append({
        "name": name,
        "name_lat": name_lat,
        "history": history,
        "pe": pe,
        "programing": programing,
        "foreign_languge": foreign_languge,
        "software_engineering": software_engineering,
        "linear_algebra": linear_algebra,
        "physics": physics,
        "integrals": integrals
        })
    f.close()
    return students



def input_all(students):
    if len(sys.argv) != 5:
        mc.postToChat("Incorrect count of arguments")
        mc.postToChat("Enter /py ap 'group_name' 'full_name'")
        sys.exit()
    input_group = sys.argv[1]
    whitespace = " "
    input_name = sys.argv[2] + whitespace + sys.argv[3] + whitespace + sys.argv[4]
    tmp = 0
    groups = ["IU7-21B","IU7-22B","IU7-23B","IU7-24B","IU7-25B","IU7-26B"]
    for i in groups:
        if input_group == i:
            tmp = 1
    if tmp == 0:
        mc.postToChat("Unknown group name")
        mc.postToChat("Enter /py ap 'group_name' 'full_name'")
        sys.exit()
    tmp = 0
    for i in range(len(students)):
        if students[i]["name_lat"] == input_name:
            tmp = 1
            search_i = i;
    if tmp == 0:
        mc.postToChat("Student not found")
        sys.exit()
    return search_i

def output_all(students, i):
    print(students[i]["name_lat"])
    for key in students[i]:
        if key == "pe":
            print("Physical education: ", students[i][key])
        if key == "physics":
            print("Physics: ", students[i][key])
        if key == "linear_algebra":
            print("Linear algebra: ", students[i][key])
        if key == "history":
            print("History: ", students[i][key])
        if key == "foreign_languge":
            print("Foreign language: ", students[i][key])
        if key == "integrals":
            print("Integrals: ", students[i][key])
        if key == "programing":
            print("Programing: ", students[i][key])
        if key == "software_engineering":
            print("Software engineering: ", students[i][key])
        
students = make_dict("data.txt","lat_data.txt")   
i = input_all(students)
output_all(students, i)
#print(students)

        


