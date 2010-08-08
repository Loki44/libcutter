/*
 * libcutter - xy cutter control library
 * Copyright (c) 2010 - libcutter Developers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Should you need to contact us, the author, you can do so either at
 * http://github.com/vangdfang/libcutter, or by paper mail:
 *
 * libcutter Developers @ Cowtown Computer Congress
 * 3101 Mercier Street #404, Kansas City, MO 64111
 */
#ifndef DEVICE_CV_SIM_HPP
#define DEVICE_CV_SIM_HPP

#include <stdint.h>
#include <opencv/cv.h>
#include "device.hpp"
#include "types.h"

namespace Device
{
    class CV_sim : public Device::Generic
    {
        public:
            CV_sim();
            CV_sim( const std::string filename );
            /* virtual */ bool move_to(const xy &aPoint);
            /* virtual */ bool cut_to(const xy &aPoint);
            /* virtual */ bool curve_to(const xy &p0, const xy &p1, const xy &p2, const xy &p3);
            /* virtual */ bool start();
            /* virtual */ bool stop();
            /* virtual */ xy   get_dimensions();
            inline IplImage * get_image(){return image;};
        private:
            xy convert_to_internal( const xy &input );
            xy current_position;
            std::string output_filename;
            bool running;
            IplImage * image;
    };
}
#endif
