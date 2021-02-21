/**
 * Challenge: Download a collection of images
 */
#include <thread>
#include <cstring>
#include <curl/curl.h> // curl support https://curl.haxx.se/

/* declarations for download_image helper function */
size_t download_image(int image_num);
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp);

/* sequential implementation of image downloader */
size_t sequential_image_downloader(int num_images) {
	size_t total_bytes = 0;
	for (int i=1; i<=num_images; i++) {
		total_bytes += download_image(i);
	}
	return total_bytes;
}

/* parallel implementation of image downloader */
size_t parallel_image_downloader(int num_images) {
	size_t total_bytes = 0;
    /***********************
     * YOUR CODE GOES HERE *
     ***********************/
	return total_bytes;
}

/* helper function to download a single image and return size in bytes */
size_t download_image(int image_num) { 
	char url[] = "http://699340.youcanlearnit.net/imageXXX.jpg";
	sprintf(url, "http://699340.youcanlearnit.net/image%03d.jpg", ((image_num % 50) + 1));

    CURLcode res;
    curl_off_t num_bytes = 0;
    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        res = curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD_T, &num_bytes);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return num_bytes;
}

/* support function for the download_image helper function */
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main() {
	const int NUM_EVAL_RUNS = 3;
	const int NUM_IMAGES = 50;

	printf("Evaluating Sequential Implementation...\n");
	std::chrono::duration<double> sequential_time(0);
    size_t sequential_result = sequential_image_downloader(NUM_IMAGES); // "warm up"
    for (int i=0; i<NUM_EVAL_RUNS; i++) {
        auto startTime = std::chrono::high_resolution_clock::now();
        sequential_image_downloader(NUM_IMAGES);
        sequential_time += std::chrono::high_resolution_clock::now() - startTime;
    }
    sequential_time /= NUM_EVAL_RUNS;

    printf("Evaluating Parallel Implementation...\n");
	std::chrono::duration<double> parallel_time(0);
    size_t parallel_result = parallel_image_downloader(NUM_IMAGES); // "warm up"
    for (int i=0; i<NUM_EVAL_RUNS; i++) {
        auto startTime = std::chrono::high_resolution_clock::now();
        parallel_image_downloader(NUM_IMAGES);
        parallel_time += std::chrono::high_resolution_clock::now() - startTime;
    }
    parallel_time /= NUM_EVAL_RUNS;
    
    // display sequential and parallel results for comparison
    if (sequential_result != parallel_result) {
        printf("ERROR: Result mismatch!\n  Sequential Result = %zd\n  Parallel Result = %zd\n", sequential_result, parallel_result);
    }
    printf("Average Sequential Time: %.2f ms\n", sequential_time.count()*1000);
    printf("  Average Parallel Time: %.2f ms\n", parallel_time.count()*1000);
    printf("Speedup: %.2f\n", sequential_time/parallel_time);
    printf("Efficiency %.2f%%\n", 100*(sequential_time/parallel_time)/std::thread::hardware_concurrency());
}