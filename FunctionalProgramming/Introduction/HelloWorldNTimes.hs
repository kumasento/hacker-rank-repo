
hello_worlds n 
    | n == 0 = return ()
    | otherwise = do
        putStrLn "Hello World"
        hello_worlds (n-1)

main = do
    n <- readLn :: IO Int
    hello_worlds n
