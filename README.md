# OS-LR6

В работе нужно разработать пять программ – одну для процесса-родителя, две – для дочерних процессов, еще две – для «внучатых» процессов. Все программы осуществляют вывод сообщений о своем «родственном»
положении (например, «родитель», «дочерний», «внук» и номер шага в цикле
вывода таких сообщений, между которыми следует задавать задержки в пределах 1-2 секунд. Число повторений таких выводов сообщений должно составлять 10 – 20 для каждой программы, задержки для них следует выбирать различные, но незначительно – отличающиеся на 30–70%). На 7 шаге для вывода
сообщений родительская программа отдает приказ об уничтожении первой дочерней и соответствующее дополнительное сообщение об этом на экран, на 11
шаге родительская программа выдает приказ об уничтожении второй дочерней
и ее потомка. Все такие программы, создающие новый процесс, должны передавать в дочерний процесс текстовую информацию о присваиваемом ею текстовом имени дочернего (аналогичном «человеческим» именам). Это имя имеет исключительно иллюстративное значение и должно выводиться каждым
процессом кроме исходного родительского с соответствующим примечанием о
его назначении.
