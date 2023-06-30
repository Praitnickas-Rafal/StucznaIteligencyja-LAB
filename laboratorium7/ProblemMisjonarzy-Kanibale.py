from collections import deque

class State:
    def __init__(self, lM, lC, boat, rM, rC, parent):
        self.lM = lM  # liczba misjonarzy po lewej stronie
        self.lC = lC  # liczba kanibali po lewej stronie
        self.boat = boat  # położenie łodzi
        self.rM = rM  # liczba misjonarzy po prawej stronie
        self.rC = rC  # liczba kanibali po prawej stronie
        self.parent = parent

    def is_valid(self):
        if self.lM >= 0 and self.rM >= 0 \
                and self.lC >= 0 and self.rC >= 0 \
                and (self.lM == 0 or self.lM >= self.lC) \
                and (self.rM == 0 or self.rM >= self.rC):
            return True
        return False

    def is_goal(self):
        return self.lM == 0 and self.lC == 0

    def generate_next_states(self):
        states = []
        if self.boat == 'left':
            # Próba zabrania 1 lub 2 misjonarzy z lewej na prawą stronę
            for i in range(3):
                for j in range(3):
                    if i + j >= 1 and i + j <= 2:
                        new_state = State(self.lM - i, self.lC - j,
                                          'right', self.rM + i, self.rC + j, self)
                        if new_state.is_valid():
                            states.append(new_state)
        else:
            # Próba zabrania 1 lub 2 misjonarzy z prawej na lewą stronę
            for i in range(3):
                for j in range(3):
                    if i + j >= 1 and i + j <= 2:
                        new_state = State(self.lM + i, self.lC + j,
                                          'left', self.rM - i, self.rC - j, self)
                        if new_state.is_valid():
                            states.append(new_state)
        return states

    def __eq__(self, other):
        return self.lM == other.lM \
               and self.lC == other.lC \
               and self.boat == other.boat \
               and self.rM == other.rM \
               and self.rC == other.rC

    def __hash__(self):
        return hash((self.lM, self.lC, self.boat, self.rM, self.rC))

    def get_left_bank(self):
        return f"M: {self.lM}   K: {self.lC}"

    def get_right_bank(self):
        return f"M: {self.rM}   K: {self.rC}"


def bfs():
    initial_state = State(3, 3, 'left', 0, 0, None)
    visited = set()
    queue = deque([initial_state])

    while queue:
        current_state = queue.popleft()
        visited.add(current_state)

        if current_state.is_goal():
            return current_state

        next_states = current_state.generate_next_states()
        for state in next_states:
            if state not in visited:
                queue.append(state)
                visited.add(state)

    return None


def print_solution(solution):
    path = []
    current_state = solution

    while current_state:
        path.append(current_state)
        current_state = current_state.parent

    path.reverse()

    for state in path:
        boat = 'left' if state.boat == 'left' else 'right'
        print(f"Lewy Brzeg:  {state.get_left_bank()}   Łódka: {boat}   Prawy Brzeg: {state.get_right_bank()}")

        if state != path[-1]:
            print("  |")

    print("\nZnaleziono rozwiązanie!")


def main():
    solution = bfs()
    if solution:
        print_solution(solution)
    else:
        print("Nie znaleziono rozwiązania.")


if __name__ == '__main__':
    main()
