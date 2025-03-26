import math

# Constants for players
PLAYER_X = 'X'
PLAYER_O = 'O'
EMPTY = ' '

def print_board(board):
    for row in board:
        print('|'.join(row))
        print('-' * 5)

def is_winner(board, player):
    # Check rows, columns, and diagonals for a win
    for row in board:
        if all([spot == player for spot in row]):
            return True
    for col in range(3):
        if all([board[row][col] == player for row in range(3)]):
            return True
    if all([board[i][i] == player for i in range(3)]) or all([board[i][2 - i] == player for i in range(3)]):
        return True
    return False

def get_empty_positions(board):
    return [(i, j) for i in range(3) for j in range(3) if board[i][j] == EMPTY]

def is_draw(board):
    return all([spot != EMPTY for row in board for spot in row])

def minimax(board, depth, is_maximizing, alpha, beta):
    if is_winner(board, PLAYER_X):
        return 10 - depth
    if is_winner(board, PLAYER_O):
        return depth - 10
    if is_draw(board):
        return 0

    if is_maximizing:
        max_eval = -math.inf
        for (i, j) in get_empty_positions(board):
            board[i][j] = PLAYER_X
            eval = minimax(board, depth + 1, False, alpha, beta)
            board[i][j] = EMPTY
            max_eval = max(max_eval, eval)
            alpha = max(alpha, eval)
            if beta <= alpha:
                break
        return max_eval
    else:
        min_eval = math.inf
        for (i, j) in get_empty_positions(board):
            board[i][j] = PLAYER_O
            eval = minimax(board, depth + 1, True, alpha, beta)
            board[i][j] = EMPTY
            min_eval = min(min_eval, eval)
            beta = min(beta, eval)
            if beta <= alpha:
                break
        return min_eval

def best_move(board, player):
    best_val = -math.inf if player == PLAYER_X else math.inf
    best_move = None
    for (i, j) in get_empty_positions(board):
        board[i][j] = player
        move_val = minimax(board, 0, player == PLAYER_O, -math.inf, math.inf)
        board[i][j] = EMPTY
        if (player == PLAYER_X and move_val > best_val) or (player == PLAYER_O and move_val < best_val):
            best_val = move_val
            best_move = (i, j)
    return best_move

def main():
    board = [[EMPTY for _ in range(3)] for _ in range(3)]
    current_player = PLAYER_X

    while True:
        print_board(board)
        if current_player == PLAYER_X:
            move = best_move(board, current_player)
        else:
            move = None
            while move not in get_empty_positions(board):
                user_input = input(f"Player {current_player}, enter your move (row and column): ")
                i, j = map(int, user_input.split())
                move = (i, j)

        if move:
            i, j = move
            board[i][j] = current_player

        if is_winner(board, current_player):
            print_board(board)
            print(f'Player {current_player} wins!')
            break
        if is_draw(board):
            print_board(board)
            print('Draw!')
            break

        current_player = PLAYER_O if current_player == PLAYER_X else PLAYER_X

if __name__ == "__main__":
    main()
