#ifndef MUSIC_H
#define MUSIC_H

#ifdef _WIN32
	#include <SDL.h>
	#include <SDL_image.h>
#elif __APPLE__
	#include "TargetConditionals.h"
	//mac
#elif __linux__
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_mixer.h>
#else
	#error "Unknown compiler"
#endif

#include <string>
#include "Resources.h"
#include "Error.h"

#define MUSIC_FADE_OUT_TIME_MSEC (2000)

using std::string;

/**
	\brief Classe que modela músicas.

	Modela músicas e permite operações básicas como: abiri um arquivo de som, tocar som e para som(stop).
	Diferente de sons, apenas uma música pode ser tocada por vez.
*/
class Music {
	public:
		/**
			\brief Construtor padrão.
			\todo Verificar a necessidade da existência desse contrutor.

			Cria uma instância não associada a nenhuma música. O uso da instâncis nesse estado pode causar problemas.
		*/
		Music();
		/**
			\brief Construtor.
			\param file Arquivo com música a ser utilizado.

			Cria uma instância associando-a uma música. Todas as funcionalidades tornam-se disponíveis.
		*/
		Music(string file);
		/**
			\brief Toca a música.
			\param times Número de vezes que a música deve repetir.

			Toca a música. Caso times seja -1, o sem será tocado indefinidamente.
		*/
		void Play(int times);
		/**
			\brief Interrompe a música.

			Interrompe a eecução da música associado à instância.
		*/
		void Stop(void);
		/**
			\brief Carrega uma música.
			\param file Arquivo com a música a ser utilizado.
			\todo Colocar para parar a música que estiver em execução?

			Associa a instância à música contido no arquivo.
		*/
		void Open(string file);
		/**
			\brief Verifica se tem um arquivo aberto
			\param return verdadeiro se essa instância está associada a uma música, falso caso contrário.

			Verifica se a instância de Music está associada à música de algum arquivo.
		*/
		bool IsOpen(void)const;
	private:
		std::shared_ptr<Mix_Music> music;/**< Ponteiro para Mix_Music com a música.*/
};

#endif // MUSIC_H
