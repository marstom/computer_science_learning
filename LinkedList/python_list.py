import random
import time

BIG = 50*1000000 #50M

def test_random():
    lista = []
    start = time.time()
    for _ in range(BIG):
        # digit = random.randint(0, 5000)
        # digit = 23
        lista.append(23)
    end = time.time()
    print('Exec time is {}'.format(end - start))


if __name__ == "__main__":
    test_random()
