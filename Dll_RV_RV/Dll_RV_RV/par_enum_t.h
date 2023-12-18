/*!
 * @file par_enum.h
 * @brief Параметр-перечисление имитатора
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
 //! Параметр-перечисление имитатора
class par_enum_t : public par_t {
public:
    /*!
     * Параметр-перечисление имитатора (деструктор)
     */
    virtual ~par_enum_t() = default;

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
 * Создает параметр-перечисление имитатора
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param text_id Текстовый идентификатор параметра
 * @param name Название
 * @param default_value Значение по умолчанию
 * @param available_values Список допустимых значений и их названий, формат: "0 A;1 B;3 C"
 * @param invalid_available Доступность состояния "не достоверный" (par_invalid_available_t)
 */
extern "C" LIBIMIT_API par_enum_t * __stdcall create_par_enum(const unsigned char list_id, const char* text_id, const char* name, const unsigned int default_value, const char* available_values, const unsigned int invalid_available = PAR_ALWAYS_VALID);

/*!
 * Уничтожает параметр-перечисление имитатора
 * @par par Уничтожаемый параметр
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_enum(par_enum_t * par);

#endif
