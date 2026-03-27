using System;
using System.IO;
using System.Text;

class VigenereCipher
{
    static void Main()
    {
        // Пути к файлам
        string messageFile = @"C:\\laba3\1.txt";
        string keyFile = @"C:\\laba3\2.txt";
        string outputFile = @"C:\\laba3\3.txt";

        // Чтение текста сообщения из файла 1.txt
        string message = File.ReadAllText(messageFile, Encoding.UTF8);

        // Чтение ключа из файла 2.txt
        string key = File.ReadAllText(keyFile, Encoding.UTF8).ToLower(); // Ключ должен быть в нижнем регистре

        // Алфавит русского языка
        string alphabet = "абвгдеёжзийклмнопрстуфхцчшщыэюя";

        // Массив символов сообщения
        char[] messageArray = message.ToCharArray();

        // Индекс для ключа
        int keyIndex = 0;

        // Применение шифра Виженера
        for (int i = 0; i < messageArray.Length; i++)
        {
            char currentChar = messageArray[i];

            // Проверка, является ли символ буквой русского алфавита
            int alphabetIndex = alphabet.IndexOf(currentChar);

            if (alphabetIndex != -1) // Если символ — буква из алфавита
            {
                // Получаем смещение по ключу
                char keyChar = key[keyIndex % key.Length]; // Повторяем ключ по кольцу
                int keyShift = alphabet.IndexOf(keyChar); // Индекс буквы ключа

                // Сдвигаем символ
                int newIndex = (alphabetIndex + keyShift) % alphabet.Length;
                messageArray[i] = alphabet[newIndex];

                // Переходим к следующему символу в ключе
                keyIndex++;
            }
            // Если символ не является буквой русского алфавита, он остаётся без изменений
        }

        // Преобразуем массив символов обратно в строку
        string encryptedMessage = new string(messageArray);

        // Записываем зашифрованное сообщение в файл 3.txt
        File.WriteAllText(outputFile, encryptedMessage, Encoding.UTF8);

        Console.WriteLine("Шифрование завершено. Результат записан в файл " + outputFile);
    }
}