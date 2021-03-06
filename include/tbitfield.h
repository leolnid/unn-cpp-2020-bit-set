// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#ifndef __BITFIELD_H__
#define __BITFIELD_H__

#include <iostream>

typedef unsigned int TELEM;
#define TYPE_MASK ((sizeof(TELEM) << 3) - 1)

class TBitField {
private:
    size_t BitLen; // длина битового поля - макс. к-во битов
    TELEM *pMem; // память для представления битового поля
    size_t MemLen; // к-во эл-тов Мем для представления бит.поля

    // методы реализации
    size_t GetMemIndex(const size_t n) const; // индекс в pМем для бита n       (#О2)
    TELEM GetMemMask(const size_t n) const; // битовая маска для бита n       (#О3)
    size_t BitLenToMem(const size_t n) const;
    size_t BitLenToMask(const size_t n) const;
public:
    TBitField(size_t len);                // Конструкток инициализатор      (#О1)
    TBitField(const TBitField &bf);       // Конструктор копирования        (#П1)
    ~TBitField();                         // Деструктор                     (#С)

    // доступ к битам
    size_t GetLength() const;          // получить длину (к-во битов)           (#О)
    void SetBit(const size_t n);       // установить бит                       (#О4)
    void ClrBit(const size_t n);       // очистить бит                         (#П2)
    void SwhBit(const size_t n);       // изменить бит
    size_t GetBit(const size_t n) const; // получить значение бита               (#Л1)

    // битовые операции
    bool operator==(const TBitField &bf) const; // сравнение                 (#О5)
    bool operator!=(const TBitField &bf) const; // сравнение
    TBitField &operator=(const TBitField &bf); // присваивание              (#П3)
    TBitField &operator|(const TBitField &bf) const; // операция "или"            (#О6)
    TBitField &operator&(const TBitField &bf) const; // операция "и"              (#Л2)
    TBitField &operator~() const;                // отрицание                  (#С)

    friend std::istream &operator>>(std::istream &istr, TBitField &bf);       //      (#О7)
    friend std::ostream &operator<<(std::ostream &ostr, const TBitField &bf); //      (#П4)

    static bool compare(const TBitField &a, const TBitField &b, bool (*compare)(TELEM, TELEM));
};
// Структура хранения битового поля
//   бит.поле - набор битов с номерами от 0 до BitLen
//   массив pМем рассматривается как последовательность MemLen элементов
//   биты в эл-тах pМем нумеруются справа налево (от младших к старшим)
// О8 Л2 П4 С2

#endif
