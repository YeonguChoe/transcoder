extern "C"
{
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/opt.h>
}

using namespace std;
int main(int argc, char *argv[])
{
    ///////////////////////// Demux using FFmpeg /////////////////////////
    // FFmpeg Demux
    const char *filename = argv[1];
    AVFormatContext *formatContext = nullptr;

    // open input file
    avformat_open_input(&formatContext, filename, nullptr, nullptr);

    // find stream
    avformat_find_stream_info(formatContext, nullptr);
    av_dump_format(formatContext, 0, filename, 0);

    // video stream
    AVStream *videoStream = formatContext->streams[0];
    AVCodecParameters *codecParams = videoStream->codecpar;

    // video codec
    const AVCodec *codec = avcodec_find_decoder(codecParams->codec_id);
    AVCodecContext *codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, codecParams);

    ///////////////////////// Decode using Nvidia /////////////////////////


    ///////////////////////// Free FFmpeg resource /////////////////////////
    // free FFmpeg resource
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);

    return 0;
}