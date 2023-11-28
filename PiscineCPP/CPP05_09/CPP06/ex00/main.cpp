/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:01:17 by yassine           #+#    #+#             */
/*   Updated: 2023/11/28 08:54:27 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Please use ./convert (argv[0])";
        return 1;
    }
    if (argc == 2) {
        ScalarConverter converter;
        converter.convert(argv[1]);
    }
    return 0;
}