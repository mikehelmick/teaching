% Bowling scoring calculation in Erlang as a rescursive function
-module(bowling).
-export([score/1]).

% To run - start an erlang shell, erl
%
% c(bowling).
% bowling:score([x, 5, 4, 2, s, x, 0, s, 0, 5, x, 5, s, 6, 2, x, 0, 1]).


% tenth frame first
score([]) -> 0;
score([_, s, x]) -> 20;
score([_, s, N]) -> 10 + N;
score([x, x, x]) -> 30;
score([x, x, N]) -> 20 + N;
score([x, _, s]) -> 20;
score([x, A, B]) -> 10 + A + B;
score([A, B]) -> A + B;
% Spare conditions
score([_, s, x | T]) -> 20 + score(lists:flatten([x, T]));
score([_, s, Next | T]) -> 10 + Next + score(lists:flatten([Next, T]));
% strike conditions
score([x, N, s | T]) -> 20 + score(lists:flatten([N, s, T]));
score([x, x, x | T]) -> 30 + score(lists:flatten([x, x, T]));
score([x, x, N | T]) -> 20 + N + score(lists:flatten([x, N, T]));
score([x, A, B | T]) -> 10 + A + B + score(lists:flatten([A, B, T]));
% normal frame
score([A, B | T]) -> A + B + score(T).
