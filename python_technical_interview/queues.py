from queue import Queue

def task(name, jobq):
    if jobq.empty():
        print(f"Task {name} has nothing to do")
    else:
        while not jobq.empty():
            count = jobq.get()
            total = 0
            print(f"Task {name} is running")
            for x in range(count):
                total += 1
            print(f"Task {name} total: {total}")

def clever_task(name,jobq):
    while not jobq.empty():
        count = jobq.get()
        total = 0
        print(f"Task {name} is running")
        for x in range(count):
            total += 1
            yield
        print(f"Task {name} total: {total}")


def main():
    workq = Queue()

    for work in [15,10,5,2]:
        workq.put(work)

    tasks = [(task,"one", workq), (task, "two", workq)]

    for t,n,q in tasks:
        t(n,q)

if __name__=="__main__":
    main()

