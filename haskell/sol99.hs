--prob 1
myLast :: [a] -> a
myLast [] = error "No end for empty lists!"
--myLast (x:[]) = x
myLast [x] = x
myLast (x:xs) = myLast xs
 
--myLast' = foldr1 (const id)
 
-- Prelude> const 1 2
-- 1
-- Prelude> (flip const) 1 2
-- 2
--myLast'' = foldr1 (flip const)
 
myLast''' = head . reverse
--
--myLast'''' = foldl1 (curry snd)
 
myLast''''' [] = error "No end for empty lists!"  
myLast''''' x = x !! (length x -1)

--prob 2
--wrong
--myButLast :: [a] -> a
--myButLast [] = error "Too few elements!"
--myButLast [x] = error "Too few elements!"
--myButLast (x1:(x2:[])) = x1
--myButLast (x:xs) = myLast xs
myButLast :: [a] -> a
myButLast = last . init
 
myButLast' x = reverse x !! 1
 
myButLast'' [x,_]  = x
myButLast'' (_:xs) = myButLast'' xs
 
myButLast''' (x:(_:[])) = x
myButLast''' (_:xs) = myButLast''' xs
 
myButLast'''' = head . tail . reverse
 
--lastbut1 :: Foldable f => f a -> a
--lastbut1 = fst . foldl (\(a,b) x -> (b,x)) (err1,err2)
--  where
--    err1 = error "lastbut1: Empty list"
--    err2 = error "lastbut1: Singleton"
 
--lastbut1safe :: Foldable f => f a -> Maybe a
--lastbut1safe = fst . foldl (\(a,b) x -> (b,Just x)) (Nothing,Nothing)
 
myButLast''''' [] = error "Empty list"
myButLast''''' [x] = error "Too few elements"
myButLast''''' (x:xs) = 
        if length xs == 1 then x
        else myButLast''''' xs

myButLast''''''''''''' [] = error "Too few elements!"
myButLast''''''''''''' [x] = error "Too few elements!"  
myButLast''''''''''''' x = x !! (length x -2)

--prob 3
elementAt :: [a] -> Int -> a
elementAt xs index
    | index == 1 = head xs
    | otherwise = elementAt (tail xs) (index-1)

elementAt' list i = list !! (i-1)
-- still working on it~