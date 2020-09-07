module Parser where

import System.Environment
import System.Exit
import System.IO
import Text.Read
import DeBruijn

-- get args
processArgs :: IO ([String])
processArgs = do
            a <- getArgs
            return a

-- Convert string to int or return -1
isNum :: String -> Int
isNum a = case readMaybe a :: Maybe Int of
          Just a -> a
          Nothing -> (-1)

-- Compare all arguments / A TERMINER
compareArguments :: [String] -> Int -> IO ()
compareArguments a b
                 | length (a) == 1 = if b /= (-1) then postAlgorithmProcess b "01" else displayHelp
                 | length (a) == 2 && (a!!1) /= "--check" && (a!!1) /= "--unique" && (a!!1) /= "--clean" = if b /= (-1) then postAlgorithmProcess b (a!!1) else do displayHelp; exitWith (ExitFailure 84)
                 | length (a) == 3 = if b /= (-1) then parseOptions b (a!!1) (a!!2) else displayHelp
                 | otherwise = if b /= (-1) then parseOptions b "01" (a!!1) else displayHelp

parseOptions :: Int -> String -> String -> IO ()
parseOptions b alp "--check" = if length alp == 0 then displayHelp else checkAlgorithm b alp
parseOptions b alp "--unique" = if length alp == 0 then displayHelp else uniqueAlgorithm b alp
parseOptions b alp "--clean" = if length alp == 0 then displayHelp else cleanAlgorithm b alp
parseOptions b alp x = displayHelp

-- Check alphabet before testing what parameter is entered
postAlgorithmProcess :: Int -> String -> IO ()
postAlgorithmProcess n str = if checkAlphaUnique str 0 == False || length str == 0
                          then displayHelp
                          else putStrLn $ generateAlgorithm n str [(str!!0)]
