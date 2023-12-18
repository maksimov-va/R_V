/*!
 * @file par_empty.h
 * @brief Пустой параметр имитатора
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

 //! Пустой параметр имитатора (вертикальный отступ в списке параметров)
class par_empty_t : public par_t {
public:
    /*!
     * Пустой параметр имитатора (вертикальный отступ в списке параметров, деструктор)
     */
    virtual ~par_empty_t() = default;

    /*!
     * Возвращает высоту отступа
     * @return Высота отступа
     */
    virtual unsigned char get_height() const = 0;
};

/*!
 * Создает пустой параметр имитатора (вертикальный отступ в списке параметров)
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param height Высота отступа
 */
extern "C" LIBIMIT_API par_empty_t * __stdcall create_par_empty(const unsigned char list_id, const unsigned char height = 26);

/*!
 * Уничтожает пустой параметр имитатора
 * @par par Уничтожаемый параметр
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_empty(par_empty_t * par);

#endif
