import random

adj = [[0.1, 0.3, 0.5, 0.1], [0, 0.5, 0.5, 0], [0.8, 0.1, 0, 0.1], [1, 0, 0, 0]]


def walk(v):
    u = random.choices(range(len(adj[v])), weights=adj[v])
    return u.pop()


def walk_until_3_twice():
    v = 0
    total = 0
    while (v := walk(v)) != 3:
        total += 1
    while (v := walk(v)) != 3:
        total += 1
    return total


N = 100_000
total = 0
for _ in range(N):
    total += walk_until_3_twice()

print(total / N)
