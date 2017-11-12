(setq coa 2)(setq cob -1)(setq exa 4)(setq exb 3)(setq const 0)    
(setq lmta1 0)(setq lmtb1 2)(setq lmta2 0)(setq lmtb2 1)
(setq n 6)(setq passo1 (/ (- lmtb1 lmta1) n))(setq passo2 (/ (- lmtb2 lmta2) n))

(defun integracao2(x)
	(setq soma 0)(setq c 0)
    
    (loop for i from 0 to n
        if(= 0 i) do(setq c 1)
		else if(= n i) do(setq c 1) 
		else if(= 0 (mod i 3)) do(setq c 2) 
		else do(setq c 3)

        do(setq y (+ (* passo2 i) lmta2))
        do(setq z (+ x (* cob (expt y exb))))
        do(terpri)
        do(format t "~f + ~f = ~f" x y z)
        do(terpri)
        do(setq soma (+ soma (* c z)))
    )
	
	(return-from integracao2 (/ (* 3 passo2 soma) 8))
)

(defun integracao1()
    (setq soma2 0)(setq d 0)
    
    (loop for i from 0 to n
        if(= 0 i) do(setq d 1)
		else if(= n i) do(setq d 1) 
		else if(= 0 (mod i 3)) do(setq d 2) 
		else do(setq d 3)
        
        do(setq x (+ (* passo1 i) lmta1))
        do(setq y (integracao2(+ (* coa (expt x exa)) const)))
        do(terpri)(terpri)
        do(format t "Parcial obtida: ~f" y)
        do(terpri)
        do(setq soma2 (+ soma2 (* y d)))
    )
    
    (return-from integracao1 (/ (* 3 passo1 soma2) 8))
)

(format t "RESULTADO FINAL: ~f " (integracao1))