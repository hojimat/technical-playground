'''Backtracking'''

def backtracking(left: int, right: int, current: str) -> None:
    '''back tracking recursion'''
    print(f"I am in: {left};{right};{current};")
    if left==right==3:
        print(current)
        print(f"I am out of: {left};{right};{current};")
        return

    if left < 3:
        backtracking(left+1, right, current+'(')
        print(f"I came back to {left};{right};{current}; in the middle of a function.")

    if right < left:
        backtracking(left, right+1, current+')')
        print(f"I came back to {left};{right};{current}; in the end of a function.")
    else:
        print("But I cannot add a closing parenthesis here, so:")

    
    print(f"I am out of: {left};{right};{current};")



if __name__=="__main__":
    backtracking(0, 0, "")
