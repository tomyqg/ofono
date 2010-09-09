/*
 *
 *  oFono - Open Source Telephony
 *
 *  Copyright (C) 2008-2010  Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

struct sim_fs;

struct sim_fs *sim_fs_new(struct ofono_sim *sim,
				const struct ofono_sim_driver *driver);

int sim_fs_read(struct sim_fs *fs, int id,
		enum ofono_sim_file_structure expected_type,
		unsigned short offset, unsigned short num_bytes,
		ofono_sim_file_read_cb_t cb, void *data);

int sim_fs_write(struct sim_fs *fs, int id, ofono_sim_file_write_cb_t cb,
			enum ofono_sim_file_structure structure, int record,
			const unsigned char *data, int length, void *userdata);

void sim_fs_free(struct sim_fs *fs);