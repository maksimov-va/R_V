/*!
 * @file par_bool_read_only.h
 * @brief Булевый параметр имитатора (только для чтения)
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
 //! Булевый параметр имитатора (только для чтения)
class par_bool_read_only_t : public par_t {
public:
    /*!
     * Булевый параметр имитатора (только для чтения, деструктор)
     */
    virtual ~par_bool_read_only_t() = default;

    /*!
     * Возвращает значение
     * @return Значение
     */
    virtual bool get_value() const = 0;

    /*!
     * Устанавливает значение
     * @param value Значение
     */
    virtual void set_value(const bool value) = 0;

    /*!
     * Возвращает значение по умолчанию
     * @return Значение по умолчанию
     */
    virtual bool get_default_value() const = 0;

#ifdef DEBUG
protected:
    bool* debug_value;          //!< Значение (для отладки)
    bool* debug_valid;          //!< Достоверность (для отладки)
    par_status_t* debug_status; //!< Состояние (для отладки)
#endif
};

/*!
 * Создает булевый параметр имитатора (только для чтения)
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param text_id Текстовый идентификатор параметра
 * @param name Название
 * @param default_value Значение по умолчанию
 */
extern "C" LIBIMIT_API par_bool_read_only_t * __stdcall create_par_bool_read_only(const unsigned char list_id, const char* text_id, const char* name, const bool default_value = false);

/*!
 * Уничтожает булевый параметр имитатора (только для чтения)
 * @par par Уничтожаемый параметр
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_bool_read_only(par_bool_read_only_t * par);

#endif
