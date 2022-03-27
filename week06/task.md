## Практикум седмица 6

### Задача 1
Реализирайте клас ( Tank / Shop ), който държи информация за :
<ul>
<li>● име ( символен низ с произволна дължина )</li>
<li>● shotPower, lifePoints за танка | openFrom, workingHours за магазина </li>
</ul>

Имплементирайте нужните setters / getters и възможност за serialize / deserialize в / от вече създаден файлов поток, свръзан с двойчен файл.
Например :
void Tank::serialize(ofstream& ofs);

### Задача 2
Спазвайки добрите ООП практики и базирайки се на
имплементациите на класовете за Танк и Магазин, реализирайте :
1. Клас Army, който представлява колекция от
Танкове. Като минимум в интерфейса на армията дайте
възможност за :
<ul>
    <li>● добавяне на нов танк в армията</li>
    <li>● сериализация / десериализация на цялата армия в двоичен файл</li>
    <li>● атака към противникова единица ( танк ) - първо определя дали армията има достатъчно огнева мощ за да разруши целта. След това пресмята колко е минималният брой
изстрели, които танкове от армията ще трява да произведат за
да разрушат целта. ( Всеки танк стреля само по веднъж, целта
е общия брой изстрели да бъде минимален).</li>
</ul>

