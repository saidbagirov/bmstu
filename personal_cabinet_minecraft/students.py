import sys
from mine import *
mc = Minecraft()
def make_dict(name, namelat):
    f = open(name, 'r')
    students = []
    i = 0
    for line in f:
        i += 1
    f.close()
    f = open(name, 'r')
    f_lat =open(namelat, 'r')
    for j in range(1, int(i / 10), 1):
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
def output_students_list(students):
    if len(sys.argv) != 2:
        mc.postToChat("Incorrect count of arguments")
        mc.postToChat("Enter /py students 'group_name'")
        sys.exit()
    input_group = sys.argv[1]
    groups = ["IU7-21B", "IU7-22B", "IU7-23B", "IU7-24B", "IU7-25B", "IU7-26B"]
    for i in groups:
        if input_group == i:
            tmp = 1
    if not tmp:
        mc.postToChat("Unknown group name")
        mc.postToChat("Enter /py students 'group_name'")
        sys.exit()
    for i in range (len(students)):
        print(students[i]["name_lat"])
    print("To see student's academic performance enter /py ap 'group_name' 'student name'")
students = make_dict("data.txt", "lat_data.txt")
output_students_list(students)