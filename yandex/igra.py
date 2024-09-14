def play(n: int, cards: list[int]) -> str:
    """
    Function takes list of cards and its length,
    and returns Petya or Vasya
    """
    petya = 0
    vasya = 0
    k = int(n/3)
    for i in range(k):
        a,b,c = cards[i*3], cards[i*3+1], cards[i*3+2]
        petya += a
        vasya += b
        if a>b:
            vasya += c
        else:
            petya += c

    if petya>vasya:
        return "Petya"

    return "Vasya"


def main():
    n = 3
    cards = [1,4,2]
    winner = play(n, cards)

    print(winner)



if __name__=='__main__':
    main()



"""
n = 3*k, for some integer k

9, a b c d e f g h i  ---> abc def ghi

a b+c
d+f e
g h+i


"""
