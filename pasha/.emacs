(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(cua-mode t nil (cua-base)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "Consolas" :foundry "outline" :slant normal :weight normal :height 181 :width normal)))))

(global-set-key '[f5]' (lambda ()
			 (interactive)
			 (compile "qmake -project")))

(global-set-key '[f6]' (lambda ()
			 (interactive)
			 (compile "qmake")))

(global-set-key '[f7]' (lambda ()
			 (interactive)
			 (compile "mingw32-make")))
