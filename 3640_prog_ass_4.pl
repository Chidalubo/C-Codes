list_count(_, [], 0).
list_count(X, [X|T], C) :- list_count(X, T, C1), C is C1 + 1.
list_count(X, [Y|T], C) :- X \= Y, list_count(X, T, C).

% Example usage:
% ?- list_count(a, [a, b, a, c, a, d], Count).
% Count = 3.

tree_size([], 0).
tree_size([Root, Left, Right], Size) :-
    tree_size(Left, LeftSize),
    tree_size(Right, RightSize),
    Size is 1 + LeftSize + RightSize.

% Example usage:
% ?- tree_size([a, [b, [], []], [c, [], []]], Size).
% Size = 3.

tree_equal([], []).
tree_equal([X, Left1, Right1], [X, Left2, Right2]) :-
    tree_equal(Left1, Left2),
    tree_equal(Right1, Right2).

% Example usage:
% ?- tree_equal([a, [b, [], []], [c, [], []]], [a, [b, [], []], [c, [], []]]).
% true.
