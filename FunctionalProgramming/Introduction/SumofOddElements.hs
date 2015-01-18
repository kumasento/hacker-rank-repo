
f [] = 0
f (x:xs) = (f xs) + (if mod x 2 == 1 then x else 0)

