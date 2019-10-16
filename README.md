#Домашняя работа 1.#

Написать программу, считающую значение формулы x4 + x3 + x2 + x + 1 за два умножения.

Реализовать алгоритм нахождения неполного частного от деления a на b (целые числа), используя только операции сложения, вычитания и умножения.

Дан массив целых чисел x[1]...x[m+n], рассматриваемый как соединение двух его отрезков: начала x[1]...x[m] длины m и конца x[m+1]...x[m+n] длины n. Не используя дополнительных массивов, переставить начало и конец.

Посчитать число "счастливых билетов" (билет считается "счастливым", если сумма первых трёх цифр его номера равна сумме трёх последних).

Написать программу проверки баланса скобок в исходной строке (т.е. число открывающих скобок равно числу закрывающих и выполняется правило вложенности скобок).

Заданы две строки: s1 и s2. Найти количество вхождений s2 в s1 как подстроки.

Написать программу, печатающую все простые числа, не превосходящие заданного числа.

Реализовать подсчет факториала (рекурсивно и итеративно).

Посчитать целую степень числа: an.

Реализовать программу, проверяющую, является ли строка палинромом.

Реализовать быструю сортировку (в рекурсивном варианте).

#Домашняя работа 2.

Напечатать все представления натурального числа N суммой натуральных слагаемых. Перестановка слагаемых нового способа не дает.

Напечатать в порядке возрастания все простые несократимые дроби, заключенные между 0 и 1, знаменатели которых не превышают n.

Реализовать консольную игру "Быки и коровы" (http://goo.gl/J1LKti).

Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный).

Даны две строки. Определить, можно ли, переставляя символы в первой строке, получить вторую строку. Хочется решение без вложенных циклов.

Написать программу, которая переставляет цифры натурального числа таким образом, чтобы образовалось наименьшее число, записанное этими же цифрами.

#Домашняя работа 3. 

Написать программу, которая считает количество непустых строк в исходном файле. Строка считается пустой, если состоит только из пробелов и табуляций (символ \t), или в ней нет символов вообще.

Дан массив размером n, в нём есть нули, надо их все переместить в конец, при этом не создавая новый массив.

Пользователи совершают действия, про каждое из них известно, сколько минут назад его сделали. Сколько пользователей совершили k действий за последние t минут?
На вход подаётся 3 числа: n, k, t -- число пользователей, необходимое число действий и временной промежуток. Затем в 2 * n строках описывается каждый пользователь: для i пользователя указывается m_i -- число действий, которое совершил пользователь, а затем m_i чисел -- сколько минут назад совершалось каждое действие.
Пример:
3 2 5
5
10 3 5 8 1
1
3
4
3 2 8 20
Ответ: 1 (только 3 пользователь совершил 2 действия за последние 5 минут).

#Домашняя работа 4.

"Считалочка" — отряд из 41-го сикария, защищавший галилейскую крепость Массада, не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян. Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего, пока не погибнут все. Самоубийство — тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить. Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу, чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам. В нашем случае участвует n воинов и убивают каждого m-го. Требуется определить номер k начальной позиции воина, который должен будет остаться последним. Считать с помощью циклического списка, который должен быть оформлен отдельным модулем.

Написать программу-телефонный справочник. Она должна уметь хранить имена и номера телефонов, в интерактивном режиме осуществлять следующие операции:
0 - выйти
1 - добавить запись (имя и телефон)
2 - найти телефон по имени
3 - найти имя по телефону
4 - сохранить текущие данные в файл.
При запуске программа должна читать данные из файла, если файла нет — начинать с пустой базы номеров. Формат представления данных в файле придумать самостоятельно.

Дан массив размерностью n x n, n — нечетное число. Вывести элементы массива при обходе его по спирали, начиная с центра.
