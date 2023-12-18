/*!
 * @file par_double.h
 * @brief Вещественный параметр имитатора
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
#include"par_t.h"
#include <cfloat>
#define DEBUG

 //! Вещественный параметр имитатора
class par_double_t : public par_t {
public:
    /*!
     * Вещественный параметр имитатора (деструктор)
     */
    virtual ~par_double_t() = default;

    /*!
     * Возвращает значение
     * @return Значение
     */
    virtual double get_value() const = 0;

    /*!
     * Устанавливает значение
     * @param value Значение
     */
    virtual void set_value(const double value) = 0;

    /*!
     * Возвращает значение по умолчанию
     * @return Значение по умолчанию
     */
    virtual double get_default_value() const = 0;

    /*!
     * Возвращает минимальное значение
     * @return Минимальное значение
     */
    virtual double get_min_value() const = 0;

    /*!
     * Возвращает максимальное значение
     * @return Максимальное значение
     */
    virtual double get_max_value() const = 0;

    /*!
     * Возвращает единицу измерения
     * @return Единица измерения
     */
    virtual const char* get_measure() const = 0;

#ifdef DEBUG
protected:
    double* debug_value;        //!< Значение (для отладки)
    bool* debug_valid;          //!< Достоверность (для отладки)
    par_status_t* debug_status; //!< Состояние (для отладки)
#endif
};

/*!
 * Создает вещественный параметр имитатора
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param text_id Текстовый идентификатор параметра
 * @param name Название
 * @param default_value Значение по умолчанию
 * @param min_value Минимальное значение
 * @param max_value Максимальное значение
 * @param measure Единица измерения параметра
 * @param invalid_available Доступность состояния "не достоверный" (par_invalid_available_t)
 */
extern "C" LIBIMIT_API par_double_t * __stdcall create_par_double(const unsigned char list_id, const char* text_id, const char* name, const double default_value = 0., const double min_value = -DBL_MAX, const double max_value = DBL_MAX, const char* measure = nullptr, const unsigned int invalid_available = PAR_ALWAYS_VALID);

/*!
 * Уничтожает вещественный параметр имитатора
 * @par par Уничтожаемый параметр
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_double(par_double_t * par);

#endif
