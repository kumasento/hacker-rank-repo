
fn n  
    | n == 0 = []
    | otherwise = (fn (n-1)) ++ [n]

