/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 08:34:41 by yassine           #+#    #+#             */
/*   Updated: 2024/01/13 08:34:43 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) 
{
    Data *data = new Data;
    data->s1 = "Hello";
    data->n = 42;
    std::cout << "Data: " << data->s1 << " " << data->n << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    Data *data2 = Serializer::deserialize(raw);
    std::cout << "Data2: " << data2->s1 << " " << data2->n << std::endl;
    delete data; 
    return 0;
}