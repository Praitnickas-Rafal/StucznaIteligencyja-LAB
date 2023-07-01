# Implementacja algorytmu DFS
def dfs_search(initial_state, goal_state, operators):
    stack = [(initial_state, [])]
    visited = set()

    while stack:
        current_state, path = stack.pop()
        visited.add(current_state)

        if current_state == goal_state:
            return path

        for operator in operators:
            next_state = operator(current_state)
            if next_state not in visited:
                stack.append((next_state, path + [operator]))

    return None


# Implementacja algorytmu BFS
from collections import deque

def bfs_search(initial_state, goal_state, operators):
    queue = deque([(initial_state, [])])
    visited = set()

    while queue:
        current_state, path = queue.popleft()
        visited.add(current_state)

        if current_state == goal_state:
            return path

        for operator in operators:
            next_state = operator(current_state)
            if next_state not in visited:
                queue.append((next_state, path + [operator]))

    return None


# Przykład użycia algorytmu DFS
def main():
    # Definicja stanu początkowego i docelowego
    initial_state = 1
    goal_state = 10

    # Lista operatorów
    operators = [
        lambda x: x + 1,
        lambda x: x * 2
    ]

    # Wywołanie algorytmu DFS
    result = dfs_search(initial_state, goal_state, operators)

    if result:
        print("Znaleziono ścieżkę:", result)
    else:
        print("Nie znaleziono ścieżki.")


# Wywołanie głównej funkcji
if __name__ == "__main__":
    main()
