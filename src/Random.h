#pragma once
#include <cstdlib>
#include <ctime>
#include <limits>

namespace ccHelp
{
	class Random
	{
	public:
		/*
		/// Change seed of random.
		/// </summary>*/
		static void ChangeSeed();

		/*
		/// Change seed of random.
		/// </summary>*/
		static void ChangeSeed(int);

		/*
		/// Returns a nonnegative random integer.
		/// </summary>
		/// <returns></returns> */
		static int RandomInt();

		/*
		/// Return a negative random integer.
		/// </summary>
		/// <returns></returns> */
		static int RandomNegativeInt();

		/*
		/// Returns a nonnegative random integer less than the maximum value.
		/// </summary>
		/// <param name="max">The maximum value.</param>
		/// <returns></returns> */
		static int RandomInt(int max);

		/*
		/// Returns a negative random integer greater than the minimum value.
		/// </summary>
		/// <param name="min">The minimum value.</param>
		/// <returns></returns> */
		static int RandomNegativeInt(int min);

		/*
		/// Returns a random integer within a specified range.
		/// </summary>
		/// <param name="min">The begining value of specified range.</param>
		/// <param name="max">The ending value of specified range. (Greater the begining value);*/
		static int RandomInt(int min, int max);

		/*
		/// Returns a nonnegative random double between 0.0 and 1.0.
		/// </summary>
		/// <returns></returns> */
		static double RandomDouble();

		/*
		/// Return a negative random double between -1.0 and 0.0.
		/// </summary>
		/// <returns></returns> */
		static double RandomNegativeDouble();

		/*
		/// Returns a nonnegative random double less than the maximum value.
		/// </summary>
		/// <param name="max">The maximum value.</param>
		/// <returns></returns> */
		static double RandomDouble(double max);

		/*
		/// Returns a negative random double greater than the minimum value.
		/// </summary>
		/// <param name="min">The minimum value.</param>
		/// <returns></returns> */
		static double RandomNegativeDouble(double min);

		/*
		/// Returns a random double within a specified range.
		/// </summary>
		/// <param name="min">The begining value of specified range.</param>
		/// <param name="max">The ending value of specified range. (Greater the begining value);*/
		static double RandomDouble(double min, double max);

		/*
		/// Returns a nonnegative random float between 0f and 1f
		/// </summary>
		/// <returns></returns> */
		static float RandomFloat();

		/*
		/// Returns a negative random float.
		/// </summary>
		/// <returns></returns> */
		static float RandomNegativeFloat();

		/*
		/// Returns a nonnegative random float less than the maximum value.
		/// </summary>
		/// <param name="max">The maximum value.</param>
		/// <returns></returns> */
		static float RandomFloat(float max);

		/*
		/// Returns a negative random float greater than the minimum value.
		/// </summary>
		/// <param name="min">The minimum value.</param>
		/// <returns></returns> */
		static float RandomNegativeFloat(float min);

		/*
		/// Returns a random float within a specified range.
		/// </summary>
		/// <param name="min">The begining value of specified range.</param>
		/// <param name="max">The ending value of specified range. (Greater the begining value);*/
		static float RandomFloat(float min, float max);

		/*
		/// Returns a random char.
		/// </summary>
		/// <returns></returns> */
		static char RandomByte();

		/*
		/// Returns a random char less than the maximum value.
		/// </summary>
		/// <param name="max">The maximum value.</param>
		/// <returns></returns> */
		static char RandomByte(char max);

		/*
		/// Returns a nonnegative random char within a specified range.
		/// </summary>
		/// <param name="min">The begining value of specified range.</param>
		/// <param name="max">The ending value of specified range. (Greater the begining value)</param>*/
		static char RandomByte(char min, char max);

		/*
		/// Random a logic (boolean) value with specified true ratio
		/// </summary>
		/// <param name="trueRatio">True ratio (default is 0.5)</param>
		/// <returns>Random logic value</returns> */
		static bool RandomBool(float trueRatio);

		/*
		/// Random a logic (boolean) value with specified true ratio
		/// </summary>
		/// <param name="trueRatio">True ratio (default is 0.5)</param>
		/// <returns>Random logic value</returns> */
		static bool RandomBool();
	};
}