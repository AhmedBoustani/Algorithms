(* Ahmed Amine Boustani
 * 
 * Collatz Conjecture -
 *     Start with a number n > 1.
 * 	   Find the number of steps it takes to reach one using the following process:
 *          If n is even, divide it by 2.
 *          If n is odd, multiply it by 3 and add 1.
 *)

 fun collatz (n) =
 	if n = 1 then 0
 	else if n mod 2 = 0 then 1 + collatz(n div 2)
 	else 1 + collatz(n * 3 + 1)

fun collatz_series (n) =
	if n = 1 then 1 :: []
 	else if n mod 2 = 0 then n :: collatz_series(n div 2)
 	else n :: collatz_series(n * 3 + 1)

fun collatz_max (n) =
	let 
		fun max xs =
			if null xs then 0
			else if null (tl xs) then hd xs
			else
				let 
					val tl_ans = max(tl xs)
				in
					if hd xs > tl_ans then hd xs
					else tl_ans
				end
	in
		max(collatz_series(n))
	end
