def main():
    with open("input.txt", "r") as file:
        jj = file.readline().strip()
        ss = file.readline().strip()

    count = 0
    for i in ss:
        if i in jj:
            count+=1

    print(count)

main()
