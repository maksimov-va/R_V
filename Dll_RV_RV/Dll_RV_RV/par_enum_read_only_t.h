/*!
 * @file par_enum_read_only.h
 * @brief Параметр-перечисление имитатора (только для чтения)
 * @author Илья Кулаков
 * @copyright АО ОКБ "Электроавтоматика", НИЦ-1
 * @details
 * #### Номер ВИДК
 *    нет
 * #### Комментарии
 *    нет
 */
#pragma once
#ifdef __cplusplus
#include "par_t.h"
#define DEBUG

 //! Параметр-перечисление имитатора (только для чтения)
class par_enum_read_only_t : public par_t {
public:
    /*!
     * Параметр-перечисление имитатора (только для чтения, деструктор)
     */
    virtual ~par_enum_read_only_t() = default;

    /*!
     * Возвращает значение
     * @return Значение
     */
    virtual unsigned int get_value() const = 0;

    /*!
     * Устанавливает значение
     * @param value Значение
     */
    virtual void set_value(const unsigned int value) = 0;

    /*!
     * Возвращает значение по умолчанию
     * @return Значение по умолчанию
     */
    virtual unsigned int get_default_value() const = 0;

    /*!
     * Возвращает минимальное значение
     * @return Минимальное значение
     */
    virtual unsigned int get_min_value() const = 0;

    /*!
     * Возвращает максимальное значение
     * @return Максимальное значение
     */
    virtual unsigned int get_max_value() const = 0;

#ifdef DEBUG
protected:
    unsigned int* debug_value;  //!< Значение (для отладки)
    bool* debug_valid;          //!< Достоверность (для отладки)
    par_status_t* debug_status; //!< Состояние (для отладки)
#endif
};

/*!
 * Создает параметр-перечисление имитатора (только для чтения)
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param text_id Текстовый идентификатор параметра
 * @param name Название
 * @param default_value Значение по умолчанию
 * @param available_values Список допустимых значений и их названий, формат: "0 A;1 B;3 C"
 */
extern "C" LIBIMIT_API par_enum_read_only_t * __stdcall create_par_enum_read_only(const unsigned char list_id, const char* text_id, const char* name, const unsigned int default_value, const char* available_values);

/*!
 * Уничтожает параметр-перечисление имитатора (только для чтения)
 * @par par Уничтожаемый параметр
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_enum_read_only(par_enum_read_only_t * par);

#endif
