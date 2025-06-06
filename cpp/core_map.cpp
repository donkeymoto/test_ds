#include <iostream>

using std::cout;
using std::cin;
using std::endl;
#if 0
static uint32_t find_max_free_core_buddy_long(uint16_t free_tilemap, uint32_t need_core, uint16_t *tile_map)
{
	uint8_t i;
	uint16_t test_tilemap = 0;
	uint16_t alloced_core = 0;
	*tile_map = 0;

	for (i = 0; i < need_core; i++)
		test_tilemap |= 0xF << i * 4;

	switch (need_core) {
		case 4: /* test 4 core */
			if (free_tilemap == test_tilemap) {
				*tile_map = test_tilemap;
				alloced_core = 4;
			}
			break;

		case 3: /* test 3 core */
			for (i = 0; i < 2; i++) {
				if ((free_tilemap & test_tilemap << i * 4) >> i * 4 == test_tilemap) {
					*tile_map = test_tilemap << i * 4;
					alloced_core = 3;
					break;
				}
			}
			break;

		case 2: /* test 2 core */
			for (i = 0; i < 3; i++) {
				if ((free_tilemap & test_tilemap << i * 4) >> i * 4 == test_tilemap) {
					*tile_map = test_tilemap << i * 4;
					alloced_core = 2;
					break;
				}
			}
			break;

		case 1: /* test 1 core */
			for (i = 0; i < 4; i++) {
				if ((free_tilemap & test_tilemap << i * 4) >> i * 4 == test_tilemap) {
					*tile_map = test_tilemap << i * 4;
					alloced_core = 1;
					break;
				}
			}
			break;
		default:
			pr_err("Invalid core number requestion!\n");

	}

	return alloced_core;
}
#endif


#if 0
static uint8_t find_max_free_core_map(uint16_t free_tilemap, uint32_t need_core, uint16_t *tile_map)
{
        uint8_t i;
				*tile_map = 0;
				uint32_t num_core = 0;

        for (i = 0; i < 4; i++) {
                if ((free_tilemap & 0xf << i * 4) >> i * 4 == 0xf) {
												num_core ++;
												if (num_core <= need_core)
                        	*tile_map |= (0xf << i * 4);
                }
        }

        return num_core;
}
#endif
static uint8_t find_max_free_core_map(uint16_t free_tilemap, uint32_t need_core, uint16_t *tile_map)
{
        uint8_t i;
				uint16_t temp_tilemap = 0;
        uint32_t alloced_core = 0;

				if (need_core == 0)
					return 0;

	*tile_map = 0;

        for (i = 0; i < 4; i++) {
                if ((free_tilemap & 0xf << i * 4) >> i * 4 == 0xf) {
                        alloced_core ++;
                        temp_tilemap |= (0xf << i * 4);
                        if (alloced_core >= need_core) {
													*tile_map = temp_tilemap;
													return alloced_core;
												}
                }
        }

        return 0;
}

static uint32_t find_max_free_core_buddy(uint16_t free_tilemap, uint32_t need_core, uint16_t *tile_map)
{
	uint8_t i;
	uint16_t test_tilemap = 0;
	uint16_t alloced_core = 0;
	uint16_t max_core = 4;
	*tile_map = 0;

	for (i = 0; i < need_core; i++)
		test_tilemap |= 0xF << i * 4;

	for (i = 0; i < 4 - need_core +1; i++) {
		if ((free_tilemap & test_tilemap << i * 4) >> i * 4 == test_tilemap) {
					*tile_map = test_tilemap << i * 4;
					alloced_core = need_core;
					break;
		}
	}

	return alloced_core;
}


int main(void)
{
	uint16_t free_tilemap, tile_map = 0;
	uint32_t core_num, need_core;

	cout << "Please input free tile: ";
	cin >> std::hex >> free_tilemap;

	cout << "Please input need core: ";
	cin >> std::hex >> need_core;

	while (free_tilemap) {
		core_num = find_max_free_core_map(free_tilemap, need_core, &tile_map);
		//core_num = find_max_free_core_buddy(free_tilemap, need_core, &tile_map);
		cout << "tilemap alloced " << std::hex << tile_map << endl;
		cout << "core alloced: " << core_num << endl;

		cout << "\n\nPlease input free tile: ";
		cin >> std::hex >> free_tilemap;

		cout << "Please input need core: ";
		cin >> std::hex >> need_core;
	}
}
