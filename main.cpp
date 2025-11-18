extern "C"
{
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
}

using namespace std;
int main(int argc, char *argv[])
{
    // FFmpeg
    const char *filename = argv[1];
    AVFormatContext *formatContext = nullptr;
    avformat_open_input(&formatContext, filename, nullptr, nullptr);
    avformat_find_stream_info(formatContext, nullptr);
    av_dump_format(formatContext, 0, filename, 0);

    int videoStreamIndex = -1;
    for (int i = 0; i < formatContext->nb_streams; i++)
    {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            videoStreamIndex = i;
            break;
        }
    }


    AVStream *videoStream = formatContext->streams[videoStreamIndex];
    AVCodecParameters *codecParams = videoStream->codecpar;

    const AVCodec *codec = avcodec_find_decoder(codecParams->codec_id);
    AVCodecContext *codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, codecParams);
    avcodec_open2(codecContext, codec, nullptr);



    return 0;
}